function [answer,row,col]=map_read
%Read the map from the file and return the char matrix,row length and col
%length extend to arbitrary length inspired by Jiache
s=input('Input the name of the map file: ','s');
fid=fopen(s,'r');
errmsg='Fail to open';
if (fid<0)
   disp(errmsg); 
end
%Below part inspired by Jiache~
fst_line = fgetl(fid);%in this way, we don't need to handle /r /n
ind = strfind(fst_line,' ');
row = str2double(fst_line(1:ind-1));
col = str2double(fst_line(ind+1:length(fst_line)));
%88:X 46:. 116:t 115:s
line_len=col+2;%number of col + /r /n
answer=zeros(row,col);
cnt=1;
while(cnt<=row)
    one_line=fread(fid,line_len).';
    answer(cnt,:)=one_line(1:col);
    cnt=cnt+1;
end
answer=char(answer);
fclose(fid);%remember this
end

