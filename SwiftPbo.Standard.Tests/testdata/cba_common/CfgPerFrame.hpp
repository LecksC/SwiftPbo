// Control types
#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUT_BUTTON  16 // Arma 2 - textured button

#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_USER             99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_List_N_Box       102 // Arma 2 - N columns list box


// Static styles
#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0c

#define ST_TYPE           0xF0
#define ST_SINGLE         0
#define ST_MULTI          16
#define ST_TITLE_BAR      32
#define ST_PICTURE        48
#define ST_FRAME          64
#define ST_BACKGROUND     80
#define ST_GROUP_BOX      96
#define ST_GROUP_BOX2     112
#define ST_HUD_BACKGROUND 128
#define ST_TILE_PICTURE   144
#define ST_WITH_RECT      160
#define ST_LINE           176

#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200
#define ST_KEEP_ASPECT_RATIO  0x800

#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           0x400

#define SL_TEXTURES       0x10

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

#define FontM             "Bitstream"
#define DEFAULTFONT       FontM

#define true              1
#define false             0

class RscMapControl {
    class Task;
    class CustomMark;
    class Legend;
    class Bunker;
    class Bush;
    class Busstop;
    class Command;
    class Cross;
    class Fortress;
    class Fuelstation;
    class Fountain;
    class Hospital;
    class Chapel;
    class Church;
    class Lighthouse;
    class Quay;
    class Rock;
    class Ruin;
    class SmallTree;
    class Stack;
    class Tree;
    class Tourism;
    class Transmitter;
    class ViewTower;
    class WaterTower;
    class Waypoint;
    class WaypointCompleted;
    class ActiveMarker;
};
class CBA_Dummy_Map: RscMapControl {
    idc = -1;

    type=100;
    style=48;

    x = -10;
    y = -10;
    w = 1;
    h = 1;

    colorBackground[] = {1.00, 1.00, 1.00, 0};
    colorText[] = {0.00, 0.00, 0.00, 0};
    colorSea[] = {0.56, 0.80, 0.98, 0};
    colorForest[] = {0.60, 0.80, 0.20, 0};
    colorRocks[] = {0.50, 0.50, 0.50, 0};
    colorCountlines[] = {0.65, 0.45, 0.27, 0};
    colorMainCountlines[] = {0.65, 0.45, 0.27, 0};
    colorCountlinesWater[] = {0.00, 0.53, 1.00, 0};
    colorMainCountlinesWater[] = {0.00, 0.53, 1.00, 0};
    colorForestBorder[] = {0.40, 0.80, 0.00, 0};
    colorRocksBorder[] = {0.50, 0.50, 0.50, 0};
    colorPowerLines[] = {0.00, 0.00, 0.00, 0};
    colorNames[] = {0.00, 0.00, 0.00, 0};
    colorInactive[] = {1.00, 1.00, 1.00, 0};
    colorLevels[] = {0.00, 0.00, 0.00, 0};
    colorRailWay[] = {0.00, 0.00, 0.00, 0};
    colorOutside[] = {0.56, 0.80, 0.98, 0};

    font = "TahomaB";
    sizeEx = 0.00;

    stickX[] = {0.0, {"Gamma", 1.00, 1.50} };
    stickY[] = {0.0, {"Gamma", 1.00, 1.50} };
    ptsPerSquareSea = 0;
    ptsPerSquareTxt = 0;
    ptsPerSquareCLn = 0;
    ptsPerSquareExp = 0;
    ptsPerSquareCost = 0;
    ptsPerSquareFor = "0f";
    ptsPerSquareForEdge = "0f";
    ptsPerSquareRoad = 0;
    ptsPerSquareObj = 0;

    fontLabel = "PuristaMedium";
    sizeExLabel = 0.0;
    fontGrid = "PuristaMedium";
    sizeExGrid = 0.0;
    fontUnits = "PuristaMedium";
    sizeExUnits = 0.0;
    fontNames = "PuristaMedium";
    sizeExNames = 0.0;
    fontInfo = "PuristaMedium";
    sizeExInfo = 0.0;
    fontLevel = "PuristaMedium";
    sizeExLevel = 0.0;
    scaleMax = 1;
    scaleMin = 0.125;
    text = "";

    maxSatelliteAlpha = 0;     // Alpha to 0 by default
    alphaFadeStartScale = 1.0;
    alphaFadeEndScale = 1.1;   // Prevent div/0

    showCountourInterval=1;
    scaleDefault = 2;

    class Task: Task {
        //icon = "\A3\ui_f\data\map\mapcontrol\taskIcon_CA.paa";
        color[] = {1, 0.537000, 0, 0};
        size = 27;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
        iconCreated = "";
        iconCanceled = "";
        iconDone = "";
        iconFailed = "";
        colorCreated[] = {1, 1, 1, 0};
        colorCanceled[] = {1, 1, 1, 0};
        colorDone[] = {1, 1, 1, 0};
        colorFailed[] = {1, 1, 1, 0};
    };

    class CustomMark: CustomMark {
        //icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
        color[] = {0.647100, 0.670600, 0.623500, 0};
        size = 18;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
    };

    class Legend: Legend {
        x = "SafeZoneX";
        y = "SafeZoneY";
        w = 0.340000;
        h = 0.152000;
        font = "PuristaMedium";
        sizeEx = 0.039210;
        colorBackground[] = {0.906000, 0.901000, 0.880000, 0};
        color[] = {0, 0, 0, 0};
    };

    class Bunker: Bunker {
        //icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
        color[] = {0.550000, 0.640000, 0.430000, 0};
        size = 14;
        importance = "1.5 * 14 * 0.05";
        coefMin = 0.250000;
        coefMax = 4;
    };

    class Bush: Bush {
        //icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
        color[] = {0.450000, 0.640000, 0.330000, 0.0};
        size = 14;
        importance = "0.2 * 14 * 0.05";
        coefMin = 0.250000;
        coefMax = 4;
    };

    class BusStop: BusStop {
        //icon = "\A3\ui_f\data\map\mapcontrol\busstop_ca.paa";
        color[] = {0.150000, 0.260000, 0.870000, 0};
        size = 12;
        importance = "1 * 10 * 0.05";
        coefMin = 0.250000;
        coefMax = 4;
    };

    class Command: Command {
        //icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
        color[] = {0, 0.900000, 0, 0};
        size = 18;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
    };

    class Cross: Cross {
        //icon = "\A3\ui_f\data\map\mapcontrol\cross_ca.paa";
        size = 16;
        color[] = {0, 0.900000, 0, 0};
        importance = "0.7 * 16 * 0.05";
        coefMin = 0.250000;
        coefMax = 4;
    };

    class Fortress: Fortress {
        //icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
        size = 16;
        color[] = {0, 0.900000, 0, 0};
        importance = "2 * 16 * 0.05";
        coefMin = 0.250000;
        coefMax = 4;
    };

    class Fuelstation: Fuelstation {
        //icon = "\A3\ui_f\data\map\mapcontrol\fuelstation_ca.paa";
        size = 16;
        color[] = {0, 0.900000, 0, 0};
        importance = "2 * 16 * 0.05";
        coefMin = 0.750000;
        coefMax = 4;
    };

    class Fountain: Fountain {
        //icon = "\A3\ui_f\data\map\mapcontrol\fountain_ca.paa";
        color[] = {0.200000, 0.450000, 0.700000, 0};
        size = 11;
        importance = "1 * 12 * 0.05";
        coefMin = 0.250000;
        coefMax = 4;
    };

    class Hospital: Hospital {
        //icon = "\A3\ui_f\data\map\mapcontrol\hospital_ca.paa";
        color[] = {0.780000, 0, 0.050000, 0};
        size = 16;
        importance = "2 * 16 * 0.05";
        coefMin = 0.500000;
        coefMax = 4;
    };

    class Chapel: Chapel {
        //icon = "\A3\ui_f\data\map\mapcontrol\chapel_ca.paa";
        color[] = {0.550000, 0.640000, 0.430000, 0};
        size = 16;
        importance = "1 * 16 * 0.05";
        coefMin = 0.900000;
        coefMax = 4;
    };

    class Church: Church {
        //icon = "\A3\ui_f\data\map\mapcontrol\church_ca.paa";
        size = 16;
        color[] = {0, 0.900000, 0, 0};
        importance = "2 * 16 * 0.05";
        coefMin = 0.900000;
        coefMax = 4;
    };

    class Lighthouse: Lighthouse {
        //icon = "\A3\ui_f\data\map\mapcontrol\lighthouse_ca.paa";
        size = 14;
        color[] = {0, 0.900000, 0, 0};
        importance = "3 * 16 * 0.05";
        coefMin = 0.900000;
        coefMax = 4;
    };

    class Quay: Quay {
        //icon = "\A3\ui_f\data\map\mapcontrol\quay_ca.paa";
        size = 16;
        color[] = {0, 0.900000, 0, 0};
        importance = "2 * 16 * 0.05";
        coefMin = 0.500000;
        coefMax = 4;
    };

    class Rock: Rock {
        //icon = "\A3\ui_f\data\map\mapcontrol\rock_ca.paa";
        color[] = {0.100000, 0.100000, 0.100000, 0.0};
        size = 12;
        importance = "0.5 * 12 * 0.05";
        coefMin = 0.250000;
        coefMax = 4;
    };

    class Ruin: Ruin {
        //icon = "\A3\ui_f\data\map\mapcontrol\ruin_ca.paa";
        size = 16;
        color[] = {0, 0.900000, 0, 0};
        importance = "1.2 * 16 * 0.05";
        coefMin = 1;
        coefMax = 4;
    };

    class SmallTree: SmallTree {
        //icon = "\A3\ui_f\data\map\mapcontrol\smalltree_ca.paa";
        color[] = {0.450000, 0.640000, 0.330000, 0.0};
        size = 12;
        importance = "0.6 * 12 * 0.05";
        coefMin = 0.250000;
        coefMax = 4;
    };

    class Stack: Stack {
        //icon = "\A3\ui_f\data\map\mapcontrol\stack_ca.paa";
        size = 20;
        color[] = {0, 0.900000, 0, 0};
        importance = "2 * 16 * 0.05";
        coefMin = 0.900000;
        coefMax = 4;
    };

    class Tree: Tree {
        //icon = "\A3\ui_f\data\map\mapcontrol\tree_ca.paa";
        color[] = {0.450000, 0.640000, 0.330000, 0.0};
        size = 12;
        importance = "0.9 * 16 * 0.05";
        coefMin = 0.250000;
        coefMax = 4;
    };

    class Tourism: Tourism {
        //icon = "\A3\ui_f\data\map\mapcontrol\tourism_ca.paa";
        color[] = {0.780000, 0, 0.050000, 0};
        size = 16;
        importance = "1 * 16 * 0.05";
        coefMin = 0.700000;
        coefMax = 4;
    };

    class Transmitter: Transmitter {
        //icon = "\A3\ui_f\data\map\mapcontrol\transmitter_ca.paa";
        color[] = {0, 0.900000, 0, 0};
        size = 20;
        importance = "2 * 16 * 0.05";
        coefMin = 0.900000;
        coefMax = 4;
    };

    class ViewTower: ViewTower {
        //icon = "\A3\ui_f\data\map\mapcontrol\viewtower_ca.paa";
        color[] = {0, 0.900000, 0, 0};
        size = 16;
        importance = "2.5 * 16 * 0.05";
        coefMin = 0.500000;
        coefMax = 4;
    };

    class Watertower: Watertower {
        //icon = "\A3\ui_f\data\map\mapcontrol\watertower_ca.paa";
        color[] = {0.200000, 0.450000, 0.700000, 0};
        size = 20;
        importance = "1.2 * 16 * 0.05";
        coefMin = 0.900000;
        coefMax = 4;
    };

    class Waypoint: Waypoint {
        //icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
        color[] = {0, 0.350000, 0.700000, 0};
        size = 16;
        importance = "2.5 * 16 * 0.05";
        coefMin = 0.500000;
        coefMax = 4;
    };

    class WaypointCompleted: WaypointCompleted {
        //icon = "\A3\ui_f\data\map\mapcontrol\waypoint_completed_ca.paa";
        color[] = {0, 0.350000, 0.700000, 0};
        size = 16;
        importance = "2.5 * 16 * 0.05";
        coefMin = 0.500000;
        coefMax = 4;
    };

    class ActiveMarker: ActiveMarker {
        color[] = {0.300000, 0.100000, 0.900000, 0};
        size = 50;
    };
};


class RscTitles {
    class CBA_FrameHandlerTitle {
        idd = 40121;
        movingEnable = 1;
        enableSimulation = 1;
        enableDisplay = 1;

        onLoad = QUOTE(_this call CBA_common_fnc_perFrameEngine);

        duration = 99999999;
        fadein  = 0;
        fadeout = 0;
        name = "CBA_FrameHandlerTitle";
        class controlsBackground {
            class dummy_map : CBA_Dummy_Map {
                idc = 40122;
                x = -10;
                y = -10;
                w = 0;
                h = 0;
            };
        };
        class objects {};
        class controls {};
    };
};
