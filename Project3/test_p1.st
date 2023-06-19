var a :int := 1
var b := 10
var c :int
var i:int := 0
var j:int
const a:int := 1
var cnt := 0

procedure p()
    put ("this is procedure_test")
    skip
    return
end p

function f(k:int,j:int):int
    result k+j+a+b
end f


% recursive test
function fib (i:int):int
    if(i = 1 or i =0) then
        result 1
    end if
    result fib(i-1) + fib(i-2)
end fib



begin
    var i :int := 0
    var j :int
    begin
        var k :int
        i := i+2
    end
    begin
        var i :int := 100
        var j :int
        var k :int
        put i
        skip
    end
    % i = 2
    put i 
    skip
end

p()
c := f(1,2)
put c
skip

loop
    i := i+1
    put i
    skip
    exit when (i>10)
end loop

i := 0
loop
    cnt := cnt+1
    j := 0
    loop
        i := i+1
        j := j+1
        put i
        skip
        exit when (j>5)
    end loop
    exit when (cnt=5)
end loop

put i
skip


for i:1..5
    for j:1..5
        put("*")
    end for
    skip
end for

for i:1..5
    for j:1..5
        if(i=j) then
            put("*")
        else
            put("-")
        end if
    end for
    skip
end for


if (true) then
        put ("t")
        skip
        if (i = 6) then
            put("i=6")
            skip
        end if
    else
        put("f")
        skip
end if

put ("call recursive fib(5): ")
put fib(5)
skip

cnt:=0
begin
    const a:int := 5
    const b:int := 10
    put 1+2+3+a
    skip
    put 5+b+1
    skip
    put 5+b+1 > 1+2+3+a
    skip
    put ("difference: ")
    put (5+b+1) - (1+2+3+a)
    skip
    for i: 1+2+3+a .. 5+b+1
        put i
        skip
        cnt := cnt+1
    end for
    put cnt
    skip
end