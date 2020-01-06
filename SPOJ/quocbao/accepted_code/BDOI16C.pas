const fi='BDOI16C.inp';
      fo='BDOI16C.out';
        base = 10007;
        maxn=3000;
var f,g:array[-1..2000,-1..maxn+10]of longint;
    gt:array[-1..maxn]of longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure tienxuli;
var i,j,t:longint;
    begin
        gt[0]:=1;
        for i:=1 to 2000 do gt[i]:=(gt[i-1]*i) mod base;
        f[1,0]:=1;
        for i:=2 to 2000 do
            begin
            t:=0;
            for j:=0 to maxn do
                begin
                    t:=(t+f[i-1,j]) mod base;
                    if j>=i then
                        begin
                            t:=(t-f[i-1,j-i]+base)mod base;
                        end;
                    f[i,j]:=t;
                end;
            end;
        for i:=2 to 2000 do
            begin
                for j:=1 to maxn do
                    g[i,j]:=(f[i,j-1]+g[i,j-1]) mod base;
            end;
        g[1,0]:=1;
        for i:=2 to 2000 do
            begin
                for j:=0 to maxn do
                    g[i,j]:=(gt[i]-g[i,j] +base) mod base
            end;
    end;
procedure nhap;
    var i,test,n,k:longint;
        begin
            read(tesT);
            for i:=1 to test do
                begin
                    readln(n,k);
                    writeln('Case ',i,': ',g[n,k]);
                end;
        end;
begin
 //   mo;
    tienxuli;
    nhap;
 //   dong;
end.

