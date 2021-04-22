class Vektor {
private:
	int dimension;
	int* daten;
public:
	Vektor(int dim);
	virtual ~Vektor();
	void set(int i, int val);
	int get(int i);
	int bin_suche(int sw);
};
