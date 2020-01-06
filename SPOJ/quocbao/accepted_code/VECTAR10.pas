uses math;
var  pow:array[0..100]of int64;
    i,n:longint;
begin
    //assign(input,'vectar10.inp');reset(input);
    //assign(output,'vectar10.out');rewrite(output);
        while eof=false do
            begin
                readln(n);
                if n=0 then exit;
                if (n and (n-1))=0 then writeln(n) else
                    begin
                        n:=n-(1 shl (trunc(log2(n))));
                        writeln(2*n);
                    end;
            end;
    //closE(input);closE(output);
end.

