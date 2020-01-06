uses math;
const fi='gcj082a.inp';
      fo='gcj082a.out';
        oo=round(1e9);
var n,v,test,test1:longint;
    f:array[0..10000,0..1]of longint;
    b,c:array[0..round(1e4)]of longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure nhap;
    var i,j,nn,nnn:longint;
        begin
            readln(n,v);
            for i:=1 to n do
                for j:=0 to 1 do f[i,j]:=oo;
            for i:=1 to (n-1) div 2 do
                readln(b[i],c[i]);
            for i:=i+1 to n do
                begin
                    readln(j);
                    f[i,j]:=0;
                end;
        end;
procedure xulicon(i,aa,bb:longint);
    begin
        if (f[i*2,aa]<>oo) and (f[i*2+1,bb]<>oo) then
            begin
                //and
                if b[i]=1 then
                    f[i,aa and bb]:=min(f[i,aa and bb],f[i*2,aa]+f[i*2+1,bb])
                else
                    f[i,aa or bb]:=min(f[i,aa or bb],f[i*2,aa]+f[i*2+1,bb]);
            end;
    end;
procedure xulilenh(i,aa,bb:longint);
    begin
        if (f[i*2,aa]<>oo) and (f[i*2+1,bb]<>oo) then
            begin
                //doi and thanh or
                if b[i]=1 then
                    f[i,aa or bb]:=min(f[i,aa or bb],f[i*2,aa]+f[i*2+1,bb]+1)
                else
                    f[i,aa and bb]:=min(f[i,aa and bb],f[i*2,aa]+f[i*2+1,bb]+1);
            end;
    end;
procedure xuli;
    var i:longint;
        begin
            for i:=n downto 2 do
                if i mod 2=0 then
                    begin
                                xulicon(i div 2,0,0);
                                xulicon(i div 2,0,1);
                                xulicon(i div 2,1,0);
                                xulicon(i div 2,1,1);
                                if c[i div 2]=1 then
                                    begin
                                        xulilenh(i div 2,0,0);
                                        xulilenh(i div 2,0,1);
                                        xulilenh(i div 2,1,0);
                                        xulilenh(i div 2,1,1);
                                    end;
                    end;
            //writeln;
            //for i:=1 to n do writeln(f[i,0],' ',f[i,1]);
        end;
begin
  //  mo;
    readln(test);
    for test1:=1 to test do
        begin
            write('Case #',test1,': ');
            nhap;
            xuli;
            if f[1,v]=oo then writeln('IMPOSSIBLE') else writeln(f[1,v]);
        end;
   // dong;
end.
