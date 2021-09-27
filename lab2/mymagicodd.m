function [answer] = mymagicodd(input_number)
%REQUIRE: input_number:an odd int
%EFFECT: Based on the input_number, use the method introduced in l2.pdf to
%generate a magic matrix

%Judge whether input is valid
if mod(input_number,2)==0
    fprintf("Not an odd number!\n");
end
%Initialize the answer matrix
answer=zeros(input_number);
%Set the middle of the first row to 1
mid=(input_number+1)/2;
answer(1,mid)=1;
cur_row=1;
cur_col=mid;
cnt=1;%which number to be placed
while (cnt~=input_number^2)
    %Calculate the location to place the next number
    if(cur_row-1<=0)
        next_row=input_number;
    else
        next_row=cur_row-1;
    end
    
    if(cur_col+1>input_number)
        next_col=1;
    else
        next_col=cur_col+1;
    end
    %Update the number to be the one to place
    cnt=cnt+1;
    %Judge whether the calculated place has been occupied and update the
    %location
    if (answer(next_row,next_col)==0)
        answer(next_row,next_col)=cnt;
        cur_row=next_row;
        cur_col=next_col;
    else
        answer(cur_row+1,cur_col)=cnt;
        cur_row=cur_row+1;
    end
end
end

