/***
����Ʒ���߹���ֵ�������ؼ����ڵ�һ�ε���Ҫ���⣬
��ΪĿ��״̬��һ����ֹ״̬���ŵ�����ѭ����������
�ٽ���״̬�ر��������޵ģ���ɢ��
�������̲��õ����첽��������ÿһ���ڲ�ѭ���ҵ����ŵ�
�ر��������������ر����Ա���֮���ڵ�״̬���������µ�����
*/

/****
ֵ����
ͬ������
12*12*7

*/


#include <iostream>
using namespace std;
#define size 12
int main()
{
    int matrix[size][size]=
    {
        {0,1,0,0,1,0,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,1,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,1,0,0,1,0,1},
        {0,0,0,0,0,0,0,1,0,0,1,0}
    };
    double reward[size]=
    {
        -0.02,-0.02,-0.02,1,
        -0.02,0,-0.02,-1,
        -0.02,-0.02,-0.02,-0.02
    };
    double maxreward[size]= {0,0,0,0,0,0,0,0,0,0,0,0};
    int action[size]= {4,0,1,-1,8,-1,10,-1,9,8,9,10}; //��������{1,2,3,4}
    int i=0,j=0,count=0;
    bool flag=0;
    for(i=0;i<size;i++)
        maxreward[i]=reward[i];
    while(!flag)
    {
        flag=1;
        for(i=0; i<size; i++)
        {
            if(action[i]>0||action[i]==0)
                maxreward[i]=reward[i]+maxreward[action[i]];
            else
                maxreward[i]=reward[i];
        }//�ŵ�����ζ��ͬ�����£�count=1008��12*12��7������ɨ��7��
        for(i=0; i<size; i++)//��ÿһ��״̬������V(s)
        {
            for(j=0; j<size; j++)//���Ե����Ļ�������ʵ���Ի���ɨһ����Լ�����Ҳ���Ǻ�ֵ������ͬ�ĵط�
            {
                //cout<<"i="<<i<<"  "<<maxreward[i]<<"  "<<endl;
                if(matrix[i][j]==1&&maxreward[j]>maxreward[i]-reward[i]+0.0001)//�����ۻ��ر�
                {
                    action[i]=j;
                    //if(action[i]>0||action[i]==0)
                        //maxreward[i]=reward[i]+maxreward[action[i]];//�ŵ������첽���£�
                    //else
                      //  maxreward[i]=reward[i];
                    flag=0;//���ۻ��ر����ٸ��£����������if����ô�ͽ�������
                }
                count++;
            }
        }
    }
    for(i=0; i<size; i++)
    {
        cout<<action[i]+1<<"    ";
    }
    cout<<endl;
    for(i=0; i<size; i++)
    {
        cout<<maxreward[i]<<"  ";
    }
    cout<<endl<<"count="<<count<<endl;
    return 0;
}


/*
ֵ���� �첽���� 12*12*4
*/
/*
#include <iostream>
using namespace std;
#define size 12
int main()
{
    int matrix[size][size]=
    {
        {0,1,0,0,1,0,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,1,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,1,0,0,1,0,1},
        {0,0,0,0,0,0,0,1,0,0,1,0}
    };
    double reward[size]=
    {
        -0.02,-0.02,-0.02,1,
        -0.02,0,-0.02,-1,
        -0.02,-0.02,-0.02,-0.02
    };
    double maxreward[size]= {0,0,0,0,0,0,0,0,0,0,0,0};
    //double sumreward[size]={0,0,0,0,0,0,0,0,0,0,0,0};
    int i=0,j=0,count=0;
    bool flag=0;
    for(i=0; i<size; i++)
        maxreward[i]=reward[i];
    while(!flag)
    {
        flag=1;
        for(i=0; i<size; i++)//��ÿһ��״̬������V(s)
        {
            for(j=0; j<size; j++) //���ڲ��ǲ��Ե�����ֻ�ܱ������е�״̬���ҳ��ܵ��ģ��Ҹ��ŵ�
            {
                if(matrix[i][j]==1&&maxreward[j]>maxreward[i]-reward[i]+0.0001)//double���ͱȽϴ�С��ƫ�����һ��С����Ϊ����
                {
                    maxreward[i]=reward[i]+maxreward[j];//�첽����
                    flag=0;
                }
                count++;
            }
        }
    }
    for(i=0; i<size; i++)
        cout<<maxreward[i]<<"  ";
    cout<<endl<<"count="<<count<<endl;
    return 0;
}
*/

/***

���Ե���+�첽����

12*4*4
*/
/*
#include <iostream>
using namespace std;
#define size 12
#define ACTION 4
int main()
{
    int matrix[size][size]=
    {
        {0,1,0,0,1,0,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,1,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,1,0,0,1,0,1},
        {0,0,0,0,0,0,0,1,0,0,1,0}
    };
    double reward[size]=
    {
        -0.02,-0.02,-0.02,1,
        -0.02,0,-0.02,-1,
        -0.02,-0.02,-0.02,-0.02
    };
    double maxreward[size]= {0,0,0,0,0,0,0,0,0,0,0,0};
    int action[size]= {4,0,1,-1,8,-1,10,-1,9,8,9,10}; //��������{1,2,3,4}
    int ac[ACTION]={-4,1,4,-1};
    int i=0,j=0,count=0;
    bool flag=0;
        for(i=0;i<size;i++)
        maxreward[i]=reward[i];
    while(!flag)
    {
        flag=1;
        for(i=0; i<size; i++)//��ÿһ��״̬������V(s)
        {
            for(j=0; j<ACTION; j++)//���Ե����Ļ�������ʵ���Ի���ɨһ����Լ�����Ҳ���Ǻ�ֵ������ͬ�ĵط�
            {
                //cout<<"i="<<i<<"  "<<maxreward[i]<<"  "<<endl;
                if(matrix[i][ac[j]+i]==1&&maxreward[ac[j]+i]>maxreward[i]-reward[i]+0.0001)
                {
                    action[i]=j;
                    //if(reward[i]!=1&&reward[i]!=-1)
                        maxreward[i]=reward[i]+maxreward[ac[j]+i];
                    //else
                    //    maxreward[i]=reward[i];
                    flag=0;
                }
                count++;
            }
        }
    }
    for(i=0; i<size; i++)
    {
        cout<<action[i]+1<<"    ";
    }
    cout<<endl;
    for(i=0; i<size; i++)
    {
        cout<<maxreward[i]<<"  ";
    }
    cout<<endl<<"count="<<count<<endl;
    return 0;
}
*/
