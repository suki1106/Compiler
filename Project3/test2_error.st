%% test declaration

var a: array 1..10 of int 
var t: array 1..6 of real
var z:int

const z:int := 100


%% test func_dec

%% function decclaration
function add (a :int, b :int) :int
    result true
end add

function cool():int
    result 1.0
end cool


begin
    var s:int
    var s1:int
    begin
        var s:int
        var s2:real
        begin 
            var s:int
            var s3:real
        end 

end

if true then 
    var g:int
    put ("hello world")
    if false then
        var g:int
        put ("false")

else
    var g:int
    put ("wow")
end if

if false then
    var g:int
    put ("false")
end if


z := a[1+2+3.0]
z := a[5.0]
z := a[true]