{$MODE OBJPFC}
const
    nmax = 15005;
var
    heap : array[1..nmax] of int64;
    nheap : integer;
    d : integer;
    res : array[1..nmax] of int64;
procedure init;
begin
    fillchar(heap,sizeof(heap),0);
    nheap:= 0;
end;
procedure upheap (i : integer);
var
    c,p : integer;
    t : int64;
begin
    c:= i;
    repeat
        p:= c div 2;
        if (p = 0) or (heap[p] >= heap[c]) then
            break;
        t:= heap[c];
        heap[c]:= heap[p];
        heap[p]:= t;
        c:= p;
    until false;
end;
procedure downheap (i : integer);
var
    c,p : integer;
    t : int64;
begin
    p:= i;
    repeat
        c:= p*2;
        if ( c < nheap) and (heap[c] < heap[c+1]) then
            inc(c);
        if (c > nheap) or (heap[p] >= heap[c]) then
            break;
        t:= heap[p];
        heap[p]:= heap[c];
        heap[c]:= t;
        p:= c;
    until false;
end;
procedure insert (i : int64);
begin
    inc(nheap);
    heap[nheap]:= i;
    upheap(nheap);
end;
procedure extract;
begin
    heap[1]:= heap[nheap];
    dec(nheap);
    if nheap > 1 then
        downheap(1);
end;
procedure doc;
var
    c : char;
    x : int64;
    tmp : int64;
    i : integer;
begin
    //assign(input,'input.inp');reset(input);
    //assign(output,'output.out');rewrite(output);
    init;
    while not seekeof(input) do
        begin
            read(c);
            if c = '+' then
                begin
                    readln(x);
                    if nheap < 15000 then
                        insert(x);
                end
            else
                begin
                    readln;
                    if nheap > 0 then
                        begin
                            tmp:= heap[1];
                            while (nheap > 0) and (heap[1] = tmp) do
                                extract;
                        end;
                end;
        end;
    d:= 0;
    while (nheap > 0) do
        begin
            tmp:= heap[1];
            while (nheap > 0) and (heap[1] = tmp) do
                extract;
            inc(d);
            res[d]:= tmp;
        end;
    writeln(d);
    for i:=1 to d do writeln(res[i]);
end;
BEGIN
    doc;
END.