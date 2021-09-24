function print_matrix(matrix)
%UNTITLED5 此处显示有关此函数的摘要
%   此处显示详细说明
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

