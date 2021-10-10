function cnt = DFS(map,row,col,src_row,src_col)
%UNTITLED 此处显示有关此函数的摘要
%   此处显示详细说明
global accessible_treasure;
answer=0;
if (map(src_row,src_col)=='t')
   accessible_treasure=accessible_treasure+1;
end
map(src_row,src_col)='v';

if (src_row-1>0&&map(src_row-1,src_col)~='v'&&map(src_row-1,src_col)~='X')
    answer=answer+DFS(map,row,col,src_row-1,src_col);
elseif (src_row+1<=row&&map(src_row+1,src_col)~='v'&&map(src_row+1,src_col)~='X')
    answer=answer+DFS(map,row,col,src_row+1,src_col);
elseif (src_col-1>0&&map(src_row,src_col-1)~='v'&&map(src_row,src_col-1)~='X')
    answer=answer+DFS(map,row,col,src_row,src_col-1);
elseif (src_col+1<=col&&map(src_row,src_col+1)~='v'&&map(src_row,src_col+1)~='X')
    answer=answer+DFS(map,row,col,src_row,src_col+1);
end
cnt=answer;
return;
end

