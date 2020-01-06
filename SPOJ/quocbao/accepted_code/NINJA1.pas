const fi='ninja1.inp';
fo='ninja1.out';
maxn=round(1e6);
var  a,b,c:array[0..maxn]of int64;
i,n,test:longint;
procedure xuli;
var t:int64;
    begin
        readln(n);
                for i:=1 to n do read(a[i]);
                for i:=1 to n do read(b[i]);
                for i:=1 to n do
                    begin
                        if a[i]>b[i] then
                            begin
                            t:=a[i];
                            a[i]:=b[i];
                            b[i]:=t;
                            end;
                    end;
                for i:=1 to n do
                    begin
                        c[i]:=0;
                        c[i]:=a[i];
                        if c[i]<c[i-1] then c[i]:=b[i];
                        if c[i]<c[i-1] then
                            begin
                            writeln('NO');
                            exit;
                            end;
                    end;
                writeln('YES');
    end;
begin
    //assign(input,fi);reset(input);
    //assign(output,fo);rewrite(output);
        readln(test);
        for test:=1 to test do
            begin
                xuli;
            end;
    //closE(input);
    //closE(output);
end.
