	pb=strlen(b);
	for(int i=0;i<strlen(b);i++)
		if(b[i]=='.')
		{
			pb=i;
			break;
		}
	b[pb]='.';

	int sb;
	for (sb = 0; sb < strlen(b); sb++)
		if(b[sb]!='0'&&b[sb]!='.')
			break;
	if(sb==strlen(b)){
		//0.00
		ob[0]='0';
		ob[1]='.';
		for(int i=0;i<n;i++)
			ob[i+2]='0';
		mb=0;
	}else{
		ob[0]='0';
		ob[1]='.';
		for(int i=0,j=sb;i<n;j++)
			if(j<strlen(b)){
				if(j==pb)
					continue;
				else{
					ob[i+2]=b[j];
					i++;
				}
			}else{
				ob[i+2]='0';
				i++;
			}
		mb = pb-sb;
		if(mb<0)
			mb++;
	}