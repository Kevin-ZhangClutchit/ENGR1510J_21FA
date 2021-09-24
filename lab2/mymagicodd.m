function [answer] = mymagicodd(input_number)
%UNTITLED2 此处显示有关此函数的摘要
%   此处显示详细说明
if mod(input_number,2)==0
    fprintf("Not an odd number!\n");
end
answer=zeros(input_number);
mid=(input_number+1)/2;
answer(1,mid)=1;
cur_row=1;
cur_col=mid;
cnt=1;
while (cnt~=input_number^2)
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
    cnt=cnt+1;
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

