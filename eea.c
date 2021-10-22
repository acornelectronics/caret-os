//Extended Euclidean Algorithm
//n*s+e*t = gcd(n,e)
int *eea(int n,int e){
    //q = quotient, r = remainder
    int a[64],b[64],q[64],r[64],
    s1[64],s2[64],s3[64],
    t1[64],t2[64],t3[64],
    i=0;
    a[i]=n;b[i]=e;
    s1[i]=1;s2[i]=0;
    t1[i]=0;t2[i]=1;
    //define functions for handling q,r,s3,t3
    void qr(){q[i]=a[i]/b[i];r[i]=a[i]%b[i];}
    void st(){s3[i]=s1[i]-q[i]*s2[i];t3[i]=t1[i]-q[i]*t2[i];}
    qr();st();
    //loop division until remainder = 0
    while (r[i]!=0){ i++;
        a[i]=b[i-1];b[i]=r[i-1];
        qr();
        s1[i]=s2[i-1];s2[i]=s3[i-1];
        t1[i]=t2[i-1];t2[i]=t3[i-1];
        st();
    }
    //return [gcd,s,t]
    return (int[]){b[i],s2[i],t2[i]};
}
