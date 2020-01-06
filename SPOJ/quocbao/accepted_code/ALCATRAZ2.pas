const fi='alcatraz2.inp';
      fo='alcatraz2.out';
var res,ans:int64;
    x:array[0..10]of longint;
    y:array[0..10]of int64;
    a:array[0..10,0..10]of longint;
    n,m:longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);close(output);
    end;
procedure nhap;
    var i,u,v:longint;
        begin
            for i:=1 to 8 do read(y[i]);readln;
            readln(m);
            for i:=1 to m do
                begin
                    readln(u,v);
                    a[u,v]:=1;
                    a[v,u]:=1;
                    //writeln(u,' ',v);
                end;
        end;
procedure xet;
    var i,j:longint;
        begin
            ans:=0;
            for i:=1 to 8 do
                if x[i]=1 then
                    begin
                        inc(ans,y[i]);
                        for j:=1 to i do
                            if x[j]=1 then
                                if a[i,j]=1 then exit;
                    end;
            {if ans>30 then
                begin
                for i:=1 to 8 do write(x[i],' ');writeln;
                writeln(ans);
                end;  }
            if ans>res then res:=ans;
        end;
procedure try(i:longint);
    var j:longint;
        begin
            for j:=0 to 1 do
                begin
                    x[i]:=j;
                    if i<8 then try(i+1) else xet;
                end;
        end;
begin
    //mo;
    nhap;
    try(1);
    writeln(reS);
    //dong;
end.
