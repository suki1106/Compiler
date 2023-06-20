% recursive test
var i:int
var a :int := 4
const z:bool := true
const z2:bool := false
function fib (i:int):int
    if(i = 1 or i =0) then
        result i
    end if
    result fib(i-1) + fib(i-2)
end fib

function mul (i:int,j:int):int
    result i*j
end mul

function add (i:int,j:int):int
    result i+j
end add

for i :1..10
    put fib(i)
    skip
end for

for i:1..10
    if(i mod 2 = 0) then
        put i
        skip
    end if
end for


put mul(fib(5)+1,fib(3))
skip

put 5+a+2
skip
put add(1+a+2+5,fib(5+a+2)+1)
skip


put z and z2
put z or z2
put not not not z

put add(add(1,1),add(1,1))
skip
put add(add(add(1,1),add(1,1)),add(add(1,1),add(1,1)) )