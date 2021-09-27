function lab2
%Main function for lab2
flag=true;%A control variable
while (flag)
    order=input('Input an odd number: ','s');
    %Judge whether input is a number
    if (order(1)<'0'||order(1)>'9')
        fprintf("Not a number!\n");
    end
    %Get the answer
    answer=mymagicodd(str2num(order));
    %Print it
    print_matrix(answer);
    %Interact with user to see whether they need to generate more magic
    %matrixs
    in=input('Wants More? (y/n) ','s');
    if strcmp(in,'y')
        continue;
    else
        break;
    end
end
end

