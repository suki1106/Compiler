{%
% Example with Functions
%}
% global variables
const a :int := 5
var c :int
var b :int
% function declaration
function add (a :int, b :int) :int
result a+b
end add
% main block
c :=1+5
b:=add(3,99)
if (c > 10) then
    put -c
    else
    if(b>10) then
        put b
    end if
    put("just for test")
end if
put "Hello World"