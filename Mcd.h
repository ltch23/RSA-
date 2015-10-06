#ifndef MCD_H
#define MCD_H

class Mcd
{
	public:
	static long long mcdBinario(long long, long long);
	static long long mcdExtendido(long long, long long);
	static long long mod(long long, long long);
	static long long  exponenciacionModular(long long ,long long  ,long long  );
};	

	long long  Mcd::mcdExtendido(long long  num1,long long  num2)
		{
	
		long long  r, t, t1, t2;
		t2=1;t1=0;
		
		while(num2 > 0 )
		{		
			long long  q= num1/num2;
			r= num1-(q*num2);
			num1=num2;
			num2=r;
		
			t=t1- (q*t2);
			t1=t2;
			t2=t;
		}
			t = t1;
		return t;
				
		};
		
	long long  Mcd::mod(long long  num1,long long   num2)
		{
			long long  q=num1/num2;
			long long   aux;
			if(num1<0)
			q--;
			aux = num1-(q*num2);
			return aux;
		
		};
		
	long long  Mcd::mcdBinario(long long  num1, long long  num2)
		{
			long long   c=1;
			while(num1%2==0 && num2%2==0)
			{
				num1=num1/2;
				num2=num2/2;
				c=2*c;
			}
			while(num1!=0)
			{
				while(num1%2==0)
					num1= num1/2;
				while(num2%2==0)
					num2= num2/2;
					long long  t=std::abs(num1-num2)/2;
				if(num1>=num2)
					num1=t;
				else
					num2=t;
			}
			return c*num2; 			
						
		};
	long long  Mcd::exponenciacionModular(long long  a, long long  n , long long  x)
	{
	long long  exp=1;
	long long  aux=mod(a,x);
	while(n>0)
	{
		if(mod(n,2)!=0)
			exp=mod((exp*aux),x);
		
		aux=mod((aux*aux),x);
		n=n/2;
	}
	return exp;
	}


#endif // GCD_H

