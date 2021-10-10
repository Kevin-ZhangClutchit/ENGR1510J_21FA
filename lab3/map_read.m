function [answer,row,col]=map_read
%Read the map from the file and return the char matrix,row length and col
%length
fid=fopen('map2.txt','r');
errmsg='Fail to open';
if (fid<1)
   disp(errmsg); 
end

in_mat=fread(fid,5);%10 /r 13 /n
row=str2num(char(in_mat(1)));
col=str2num(char(in_mat(3)));
%88:X 46:. 116:t 115:s
length=col+2;%number of col + /r /n
answer=zeros(row,col);
cnt=1;
while(cnt<=row)
    one_line=fread(fid,length).';
    answer(cnt,:)=one_line(1:col);
    cnt=cnt+1;
end
answer=char(answer);
fclose(fid);
end

