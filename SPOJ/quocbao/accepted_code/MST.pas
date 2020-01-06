const fi='MST.inp';
fo='MST.out';
maxn=round(1e6);
var d,p,heap,a,h,x,y,z,pos:array[0..maxn]of longint;

free:array[0..maxn]of boolean;
top,i,n,m,j,u:longint;
cp:int64;
procedure swap(i,j:longint);
var t:int64;
  begin
    t:=heap[i];
    heap[i]:=heap[j];
    heap[j]:=t;
    pos[heap[i]]:=i;
    pos[heap[j]]:=j;
  end;
procedure up(i:longint);
var j:longint;
  begin
    j:=i div 2;
    if d[heap[i]]>=d[heap[j]] then exit;
    swap(i,j);
    up(j);
  end;
procedure push(x:longint);
  begin
  inc(top);
  heap[top]:=x;
  pos[x]:=top;
  up(top);
  end;
procedure nhap;
  begin
    readln(n,m);
    for i:=1 to m do
      begin
        readln(x[i],y[i],z[i]);
        inc(h[x[i]]);
        inc(h[y[i]]);
      end;
    for i:=1 to n+1 do inc(h[i],h[i-1]);
    for i:=1 to m do
      begin
        a[h[x[i]]]:=y[i];
        p[h[x[i]]]:=z[i];
        a[h[y[i]]]:=x[i];
        p[h[y[i]]]:=z[i];
        dec(h[x[i]]);
        dec(h[y[i]]);
      end;
    for i:=2 to n+1 do d[i]:=maxlongint;
    push(1);
    free[1]:=true;
  end;
procedure update(v:longint);
var x:longint;
  begin
    x:=pos[v];
    if x=0 then push(v) else
      up(x);
  end;
procedure down(i:longint);
var j:longint;
  begin
  j:=i*2;
  if j>top then exit;
  if (j<top) and (d[heap[j+1]]<d[heap[j]]) then j:=j+1;
  if d[heap[i]]>d[heap[j]] then swap(i,j);
  down(j);
  end;
function pop:longint;
var t:longint;
  begin
    t:=heap[1];
    heap[1]:=heap[top];
    dec(top);
    down(1);
    exit(t);
  end;
begin
 // assign(input,fi);reset(input);
  //assign(output,fo);rewrite(output);
    nhap;
    for i:=1 to n do
      begin
        u:=pop;
        for j:=h[u]+1 to h[u+1] do
          begin
            if (free[a[j]]=false) and (d[a[j]]>p[j]) then
              begin
                d[a[j]]:=p[j];
                update(a[j]);
              end;
          end;
        free[u]:=true;
        inc(cp,d[u]);
      end;
  writeln(cp);
//closE(input);
 // close(output);
end.
