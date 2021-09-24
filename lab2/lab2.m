function lab2
flag=true;
while (flag)
    order=input('Input an odd number: ','s');
    if (order(1)<'0'||order(1)>'9')
        fprintf("Not a number!\n");
    end
    answer=mymagicodd(str2num(order));
    print_matrix(answer);
    in=input('Wants More? (y/n)','s');
    if strcmp(in,'y')
        continue;
    else
        break;
    end
end
end

