function accessible_treasure=lab3
%UNTITLED3 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
global accessible_treasure;
accessible_treasure=0;
[map,row,col]=map_read;
[src_row,src_col]=find(map=='s');
DFS(map,row,col,src_row,src_col);
disp(accessible_treasure);
end

