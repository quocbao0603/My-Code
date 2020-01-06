const fi='my02.inp';
      fo='my02.out';
        maxn=2000;
var f:array[0..maxn,0..maxn]of char;
    a:array[0..maxn]of char;
    cs:array[0..maxn]of longint;
        s:ansistring;
        n,m,i,j:longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure qs(l,r:longint);
    var i,j,m,y,yy:longint;
        x,xx:char;
        begin
            i:=l;
            j:=r;
            m:=random(r-l)+1+l;
            x:=a[m];
            y:=cs[m];
            repeat
                while (a[i]<x)or (a[i]=x) and (cs[i]<y) do inc(i);
                while (x<a[j])or (a[j]=x) and (y<cs[j]) do dec(j);
                if i<=j then
                    begin
                        xx:=a[i];
                        a[i]:=a[j];
                        a[j]:=xx;
                        yy:=cs[i];
                        cs[i]:=cs[j];
                        cs[j]:=yy;
                        inc(i);
                        dec(j);
                    end;
            until i>j;
            if i<r then qs(i,r);
            if l<j then qs(l,j);
        end;
procedure xuli;
    begin
        for i:=1 to n do a[i]:=s[i];
        for i:=1 to n do cs[i]:=i;
        qs(1,n);
        for i:=1 to n do f[i,1]:=a[i];
        for i:=2 to n do
            for j:=1 to n do
                begin
                    f[j,i]:=f[cs[j],i-1];
                end;
        for i:=1 to n do write(f[m,i]);
        writeln;
    end;
begin
   // mo;
    while true do
        begin
            readln(m);
            if m=-1 then exit;
            readln(s);
            n:=length(s);
            xuli;
        end;
   // dong;
end.
