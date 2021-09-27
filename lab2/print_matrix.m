function print_matrix(matrix)
%REQUIRE: A matrix
%EFFECT: print the matrix with space between elements in one row and one
%row one line
row=size(matrix,2);
for i = 1:row
    for j=1:row
        if j==row %The last element in one row, no need for space behind.
            fprintf('%d',matrix(i,j));
        else
            fprintf('%d ',matrix(i,j)); 
        end
    end
    fprintf('\n');
end
end

