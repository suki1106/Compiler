var cnt:int :=0
begin
    var i:int
    var j:int := 0
    for i : 1..10
        for j: 1..10
            cnt := cnt+1
        end for
        put ("after ")
        put i
        put (" ")
        put cnt
        skip
    end for
end

put ("result :")
put cnt