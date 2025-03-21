// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21

class Solution
{
public: // Topo sort
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        map<string, vector<string>> ingredient; // ingredients -> recipe, ingredients used in which which recipe
        map<string, vector<string>> recipe;     // recipe -> ingredients needed; not using vector<string> adj[n] because this will declare an int array of string vectors and we need string array of string vectors
        map<string, int> indegree;

        for (int i = 0; i < recipes.size(); i++)
        {
            for (string ing : ingredients[i])
                ingredient[ing].push_back(recipes[i]);

            recipe[recipes[i]] = ingredients[i];
            indegree[recipes[i]] = ingredients[i].size(); // when become 0 that means all ingredients are available
        }

        queue<string> q;
        for (string s : supplies) // store all suplies you have intially
            q.push(s);

        vector<string> ans;
        while (!q.empty())
        {
            string x = q.front();
            q.pop();

            if (ingredient.find(x) != ingredient.end())
            {
                for (string r : ingredient[x])
                {
                    if (--indegree[r] == 0)
                    {                     // recipes that can be made with this particular supply
                        q.push(r);        // because recipe is also used to make other recipes, that is why when a recipe is made we will again add it so that is it is needed by any other recipe
                        ans.push_back(r); // degree == 0 -> recipe is cooked
                    }
                }
            }
        }
        return ans;
    }
};