function Result=PlateGeneration
%Recursively generating a plate
%Warning FOR ENGR1510J students, a direct copy of this file will be treated
%as HC violation!
l=6;%the length of the car License
element=('0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ');
License=[];
Fir_word=randi(26)+36;
License=[License element(Fir_word)];%To each the first is Capital
License=[License ' '];
element(Fir_word)=[];
License=creation(l-1,License,element);
Result=License;
end


function [License,element]=creation(i,License,element)
if i==0
   return;
else 
    para=randi(10);
    if(mod(para,2)==0)
        candi=randi(56+i);
    else
        candi=randi(10);
    end
    License=[License element(candi)];
    element(candi)=[];
    License=creation(i-1,License,element);%recursion
end


end

