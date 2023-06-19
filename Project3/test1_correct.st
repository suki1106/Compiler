%% test declaration

const s :string := "Hey There"
const i := -25
const f := 3.14
const b :bool := true

const b1 := true
const b2 := false

var z:int



%% test func_dec

%% function decclaration
function add (a :int, b :int) :int
    result a+b
end add

function cool():int
    result 1
end cool

procedure ptest()
    var s:int
    return
end ptest


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
end

if true then 
    var g:int
    put ("hello world")
    if false then
        var g:int
        put ("false")
    end if
else
    var g:int
    put ("wow")
end if

if false then
    var g:int
    put ("false")
end if





for z: 2+3+5 .. 2+3+6
    put ("hello world")

    exit
end for

z := add(10,8)
z := cool()


put z > i
put z < i
put z >= i
put z <= i
put z = i
put z not= i


put b1 and b2
put b1 or b2
put not b1

