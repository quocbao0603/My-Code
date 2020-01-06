const fi='shub1307.inp';
      fo='shub1307.out';
var i,j,m,n,p,k,test:longint;
    a:array[0..101,0..101]of longint;
    b:array[0..101,0..101,0..500]of longint;
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
    begin
        readln(m,n,p);
        for i:=1 to m do
            begin
                for j:=1 to n do
                    read(A[i,j]);readln;
            end;
        fillchar(b,sizeof(b),0);
    end;
procedure capnhat(x,y:longint);
    begin
        for k:=a[x,y] to p do
            begin
                if b[x,y,k]=1 then continue;
                if (b[i,j,k-a[x,y]]=1) then b[x,y,k]:=1;
            end;
    end;
procedure xuli;
    begin
        for i:=1 to m do
            for j:=1 to n do
                begin
                if (i=1) and (j=1) then b[i,j,a[i,j]]:=1;
                    capnhat(i+1,j+1);
                    capnhat(i,j+1);
                    capnhat(i+1,j);
                end;
        for k:=p downto 0 do
            if b[m,n,k]=1 then
                begin
                    writeln(k);
                    exit;
                end;
        writeln(-1);
    end;
begin
    //mo;
    readln(test);
        for test:=1 to test do
            begin
                nhap;
                xuli;
            end;
   // dong;
end.
