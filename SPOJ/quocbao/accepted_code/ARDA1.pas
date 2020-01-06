const   fi='arda1.inp';
        fo='arda1.out';
        d=round(1e9)+7;
var n,m,i,j,mm,nn:longint;
    t,s:ansistring;
    hasht,pow:array[0..round(1e4)]of int64;
    hashs:array[0..2016,0..2016]of int64;
    dung:boolean;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewritE(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;

procedure nhap;
var ans:int64;
    begin
        readln(n,m);
        for i:=1 to n do
            begin
                ans:=0;
                readln(t);
                for j:=1 to m do
                    ans:=(ans*26+ord(t[j])) mod d;
                hasht[i]:=ans;
            end;

        readln(nn,mm);
        for i:=1 to nn do
            begin
                ans:=0;
                readln(s);
                for j:=1 to mm do
                    hashs[i,j]:=(hashs[i,j-1]*26+ord(s[j])) mod d;
            end;
    end;
function gethash(i,l,r:longint):int64;
var t:int64;
    begin
        t:=(hashs[i,r]- (hashs[i,l-1]*pow[r-l+1]) mod d+d ) mod d;
        exit(t);
    end;
function kt:boolean;
var k:longint;
    begin
        for k:=1 to n do
            begin
                if gethash(i+k-1,j,j+m-1)<>hasht[k] then exit(false);
            end;
        exit(true);
    end;
procedure xuli;
    begin
        for i:=1 to nn-n+1 do
            for j:=1 to mm-m+1 do
                begin
                    if kt=true then
                        begin
                        dung:=true;
                        writeln('(',i,',',j,')');
                        end;
                end;
        if dung=false then writeln('NO MATCH FOUND...');
    end;
procedure power;
    begin
        pow[0]:=1;
        for i:=1 to 2000 do pow[i]:=(pow[i-1]*26) mod d
    end;
begin
   // mo;
    power;
    nhap;//+ hash
    xuli;
   // dong;
end.
