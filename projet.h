#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED
typedef struct donne{
   std::vector<float>Xi;
   std::vector<float>Yi;
}donne;
class stat{ /*un class stat est une Template pour un objet*/
    private:
    donne Data;
    void Entrer_X();
    void saut();
    void Entrer_Y();
    void sous_affiche1();
    void sous_affiche2(std::vector<float>dt,std::string type);
    void affiche_titre();
    void affiche_tab();
    void message();
    public:
    stat();
    void affiche_premier_plan();
    void commencer_entrer();
    void Etude_serie(std::vector<float>dt,std::string type);
    float Moyenne(std::vector<float>dt);
    float Variance(std::vector<float>dt,float Xbar);
    void two_serie();
    float covariance();
};
#endif // PROJET_H_INCLUDED
