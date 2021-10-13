function [map,cnt] = DFS(map,row,col,src_row,src_col,cnt)
%carry out the DFS and update the map
if (map(src_row,src_col)=='t')
   fprintf("A treasure located at row:%d col:%d\n", src_row,src_col);
   cnt=cnt+1;
end
%What is this 'v' used for?
map(src_row,src_col)='v';
fprintf("Current map situation:\n");
disp(map);

%Why not if-elseif-else?
if (src_row-1>0&&map(src_row-1,src_col)~='v'&&map(src_row-1,src_col)~='X')
    [map,cnt] =DFS(map,row,col,src_row-1,src_col,cnt);
end
if (src_row+1<=row&&map(src_row+1,src_col)~='v'&&map(src_row+1,src_col)~='X')
    [map,cnt] =DFS(map,row,col,src_row+1,src_col,cnt);
end
if (src_col-1>0&&map(src_row,src_col-1)~='v'&&map(src_row,src_col-1)~='X')
    [map,cnt] =DFS(map,row,col,src_row,src_col-1,cnt);
end
if (src_col+1<=col&&map(src_row,src_col+1)~='v'&&map(src_row,src_col+1)~='X')
    [map,cnt] =DFS(map,row,col,src_row,src_col+1,cnt);
end
return;
end

