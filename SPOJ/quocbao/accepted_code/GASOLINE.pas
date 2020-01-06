uses math;
const fi='gasoline.inp';
      fo='gasoline.out';
        oo=round(1e9);
var  a:array[0..501,0..501]of longint;
    n,m,res,test:longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        close(input);closE(output);
    end;
procedure nhap;
    var i,j,k,u,v,w:longint;
        begin
             readln(n,m);
             for i:=1 to n do
                for j:=1 to n do
                    if i=j then a[i,j]:=0 else a[i,j]:=oo;
             for i:=1 to m do
                begin
                    readln(u,v,w);
                    inc(u);
                    inc(v);
                    a[u,v]:=min(a[u,v],w);
                    a[v,u]:=min(a[v,u],w);
                end;
             for k:=1 to n do
                 for i:=1 to n do
                    for j:=1 to n do
                        a[i,j]:=min(a[i,j],a[i,k]+a[k,j]);
             res:=-oo;
             for i:=1 to n do
                for j:=1 to n do
                    if (i<>j) then
                        begin
                        if a[i,j]>=oo then
                            begin
                            writeln(-1);
                            exit;
                            end;
                        res:=max(Res,a[i,j]);
                        end;
             writeln(reS);
        end;
begin
    //mo;
    readln(test);
    while test>0 do
        begin
            dec(test);
            nhap;
        end;
    //dong;
end.
