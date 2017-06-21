using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using Xunit;
using SwiftPbo.Standard;
namespace SwiftPbo.Standard.Tests
{
    public class Tests
    {
        public static string AssemblyDirectory
        {
            get
            {
                var location = typeof(Tests).GetTypeInfo().Assembly.Location;
                var dirPath = Path.GetDirectoryName(location);
                return dirPath;
            }
        }

        public static string TestFolder
        {
            get
            {
                return Path.Combine(AssemblyDirectory, "testdata");
            }
        }

        private byte[] _checksum;

        public Tests()
        {

            const string Sha = "2DEA9A198FDCF0FE70473C079F1036B6E16FBFCE";
            _checksum = Enumerable.Range(0, Sha.Length)
                .Where(x => x % 2 == 0)
                .Select(x => Convert.ToByte(Sha.Substring(x, 2), 16))
                .ToArray();
        }

        [Fact]
        public void OpenArchiveTest()
        {
            var pboArchive = new PboArchive(Path.Combine(TestFolder, "cba_common.pbo"));

            Assert.True(pboArchive.Files.Count == 113);

            Assert.True(pboArchive.Checksum.SequenceEqual(_checksum), "Checksum dosen't match");

            Assert.True(pboArchive.ProductEntry.Name == "prefix");

            Assert.True(pboArchive.ProductEntry.Prefix == @"x\cba\addons\common");

            Assert.True(pboArchive.ProductEntry.Addtional.Count == 3);
        }

        [Fact]
        public void CreateArchiveTest()
        {
            var outFolder = Path.Combine(TestFolder, "out1");
            if (!Directory.Exists(outFolder))
                Directory.CreateDirectory(outFolder);
            Assert.True(PboArchive.Create(Path.Combine(TestFolder, "cba_common"), Path.Combine(outFolder, "cba_common.pbo")));

            var pbo = new PboArchive(Path.Combine(outFolder, "cba_common.pbo"));

            Assert.True(pbo.Files.Count == 113);

            // checksums shoulden't match due to the time.
            Assert.False(pbo.Checksum.SequenceEqual(_checksum), "Checksum match");

            Assert.True(pbo.ProductEntry.Name == "prefix");

            Assert.True(pbo.ProductEntry.Prefix == @"x\cba\addons\common");

            Assert.True(pbo.ProductEntry.Addtional.Count == 1); // i don't add wonky shit like mikero.
        }

        [Fact]
        public void CloneArchiveTest()
        {
            var pboArchive = new PboArchive(Path.Combine(TestFolder, "cba_common.pbo"));
            pboArchive.ExtractAll(Path.Combine(TestFolder, "cba_common"));
            var files = new Dictionary<FileEntry, string>();

            foreach (var entry in pboArchive.Files)
            {
                var info = new FileInfo(Path.Combine(TestFolder, "cba_common", entry.FileName));
                Assert.True(info.Exists);
                files.Add(entry, info.FullName);
            }

            PboArchive.Clone(Path.Combine(TestFolder, "clone_common.pbo"), pboArchive.ProductEntry, files, pboArchive.Checksum);

            var cloneArchive = new PboArchive(Path.Combine(TestFolder, "clone_common.pbo"));

            Assert.True(pboArchive.Checksum.SequenceEqual(cloneArchive.Checksum), "Checksum dosen't match");

            Assert.True(pboArchive.Files.Count == cloneArchive.Files.Count, "Checksum dosen't match");

            Assert.True(pboArchive.ProductEntry.Name == cloneArchive.ProductEntry.Name, "Product name doesn't match ( " + pboArchive.ProductEntry.Name + " != " + cloneArchive.ProductEntry.Name + " )");

            Assert.True(pboArchive.ProductEntry.Prefix == cloneArchive.ProductEntry.Prefix, "Product prefix doesn't match ( " + pboArchive.ProductEntry.Prefix + " != " + cloneArchive.ProductEntry.Prefix + " )");

            Assert.True(pboArchive.ProductEntry.Addtional.Count == cloneArchive.ProductEntry.Addtional.Count, "Product addtional count doesn't match ( " + pboArchive.ProductEntry.Addtional.Count + " != " + cloneArchive.ProductEntry.Addtional.Count + " )");
        }

        [Fact]
        public void CloneAllArchivesTest()
        {
            var testfiles = Directory.GetFiles(TestFolder, "*.pbo");
            string outFolder = Path.Combine(TestFolder, "out2");
            foreach (var pboPath in testfiles)
            {
                string pboName = Path.GetFileName(pboPath);
                var pboArchive = new PboArchive(Path.Combine(TestFolder, pboName));
                var pboNameNoExt = pboName.Substring(0, pboName.Length - 4);
                string tempFolder = Path.Combine(TestFolder, pboNameNoExt);
                string outPath = Path.Combine(outFolder, pboNameNoExt + "_clone.pbo");

                // Extract the PBO so all the correct files exist.
                pboArchive.ExtractAll(tempFolder);

                // Recreate the file entry dictionary.
                var files = new Dictionary<FileEntry, string>();
                foreach (var entry in pboArchive.Files)
                {
                    string outfile = Path.Combine(tempFolder, GetFileName(entry));
                    Console.WriteLine("Creating/adding " + outfile);
                    files.Add(new FileEntry(entry.FileName,
                        GetPackingMethod(entry.PackingMethod),
                        entry.OriginalSize,
                        entry.TimeStamp,
                        entry.DataSize,
                        entry.Unknown, 
                        entry.OriginalFileName),
                        outfile);

                }

                // Clone the PBO
                PboArchive.Clone(outPath, pboArchive.ProductEntry, files, pboArchive.Checksum);

                // Read the PBO
                var cloneArchive = new PboArchive(outPath);

                //Compare the entire pbo
                AssertFilesEqual(pboPath, outPath);
            }
        }


        public string GetFileName(FileEntry entry)
        {
            return SwiftPbo.Standard.PboArchive.SterilizePath(entry.FileName);
            return Path.Combine(entry.FileName.Split(new[] { '\\', '/' }));
        }
        public void AssertFilesEqual(string actual, string expected)
        {
            if (!File.Exists(actual))
                throw new Exception(actual + " dosen't exist.");
            if (!File.Exists(expected))
                throw new Exception(expected + " dosen't exist.");
            var actualData = File.ReadAllBytes(actual);
            var expectedData = File.ReadAllBytes(expected);
            Assert.Equal(actualData, expectedData);
        }

        public ulong GetPackingMethod(PackingType type)
        {
            switch (type)
            {
                case PackingType.Packed:
                    return 0x43707273;
                /*   case PackingType.Uncompressed:
                        type = 0x0;
                        break;*/
                case PackingType.Uncompressed:
                    return 0x56657273;
            }
            throw new System.Exception("Invalid packing type");
        }

    }
}

