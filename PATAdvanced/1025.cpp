#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Student
{
    long long int id;
    int score, rank, lo_rank, lo_num;
};

bool cmp(Student s1, Student s2)
{
    return s1.score != s2.score ? s1.score > s2.score : s1.id < s2.id;
}

int main()
{
    int n , k;
    scanf("%d", &n);
    vector<Student> fin;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        vector<Student> v(k);
        for (int j = 0; j < k; j++)
        {
            scanf("%lld %d", &v[j].id, &v[j].score);
            v[j].lo_num = i;
        }
        sort(v.begin(), v.end(), cmp);
        v[0].lo_rank = 1;
        // fin.push_back(v[0]);
        for (int j = 1; j < k; j++)
        {
            v[j].lo_rank = (v[j].score == v[j - 1].score) ? (v[j - 1].lo_rank) : (j + 1);
            // fin.push_back(v[j]);
        }
        fin.insert(fin.end(),v.begin(),v.end());
    }
    sort(fin.begin(),fin.end(),cmp);
    fin[0].rank = 1;

    for(int j = 1;j < fin.size();j++){
        fin[j].rank = (fin[j].score == fin[j - 1].score)?(fin[j - 1].rank) : (j + 1);
    }
    printf("%d\n",fin.size());
    for(int i = 0;i < fin.size();i++){
        printf("%013lld %d %d %d\n",fin[i].id,fin[i].rank,fin[i].lo_num,fin[i].lo_rank);
    }
    return 0;
}