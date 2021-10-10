A = [2 7 9 7 ; 3 1 5 6 ; 8 1 2 5]
A(:,[1 4]), pause %get the 1st and 4th column of A (row,col)
A([2 3],[3 1]), pause%get a 2x2 matrix with (2nd 3rd)row x(3rd 1st)col
reshape(A,2,6), pause%reshape A to a 2x6 matrix (column first should be fullfilled) doesn't change original A
A(:), pause%Out A as a column vector, row first
flipud(A), pause%flip up and down
fliplr(A), pause%flip left and right
[A A(:,end)], pause%Join A and the last column of A(at A's right)
A(1:3,:), pause%print the first three rows of A
[A ; A(1:2,:)], pause%Join A and the first two rows of A(at A's bottom)
sum(A),pause%row vector containing the column sum
sum(A'), pause%row vector containing the column sum of transpose A ==row sum
sum(A,2), pause% a column vector containing the sum of each row
[ [ A ; sum(A) ] [ sum(A,2) ; sum(A(:)) ] ], pause % A with its column sum, row sum and whole sum display
A.' %transpose A