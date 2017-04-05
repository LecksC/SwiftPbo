/* ----------------------------------------------------------------------------
Function: CBA_fnc_getAlive

Description:
    A function used to find out who is alive in an array or a group.

Parameters:
    Array, Group or Unit

Example:
    (begin example)
    _alive = (Units player) call CBA_fnc_getAlive
    (end)

Returns:
    Array

Author:
    Rommel

---------------------------------------------------------------------------- */

#include "script_component.hpp"

private "_typename";
_typename = typename _this;
if (_typename == "OBJECT") exitwith {alive _this};

private ["_return","_array"];
_array = [];
switch (_typename) do {
    case "GROUP" : {
        _array = units _this;
    };
    case "ARRAY" :{
        _array =+ _this;
    };
};

_return = [];
{
    if (alive _x) then {
        _return pushBack _x;
    }
} foreach _array;
_return
