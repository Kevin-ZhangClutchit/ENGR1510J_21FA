function print_matrix(matrix)
%UNTITLED5 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
row=size(matrix,2);
for i = 1:row
    for j=1:row
        if j==row
            fprintf('%d',matrix(i,j));
        else
            fprintf('%d ',matrix(i,j)); 
        end
    end
    fprintf('\n');
end
end

