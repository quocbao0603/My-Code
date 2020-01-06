uses math;
var i,j,n,test,test1:longint;
    f:array[0..5]of longint;
    res:longint;
begin
    readln(test);
    for test1:=1 to test do
        begin
            readln(n);
            for i:=1 to 5 do f[i]:=0;
            for i:=1 to n do
                begin
                    read(j);
                    inc(f[j]);
                end;
            res:=f[1]+min(f[4],f[5])+min(f[2],f[3]);
            res:=max(res,f[2]+min(f[3],f[1]+min(f[4],f[5])));
            res:=max(res,f[3]+min(f[2],f[1]+min(f[4],f[5])));
            res:=max(Res,f[4]+min(f[5],f[1]+min(f[2],f[3])));
            res:=max(Res,f[5]+min(f[4],f[1]+min(f[2],f[3])));
            writeln('Case ',test1,': ',res);
        end;
end.

