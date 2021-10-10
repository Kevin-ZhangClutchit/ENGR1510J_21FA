function lab3
%Main function
[map,row,col]=map_read;
[src_row,src_col]=find(map=='s');
[~,answer]=DFS(map,row,col,src_row,src_col,0);
fprintf('Accessible Treasure number: %d\n',answer);
end

