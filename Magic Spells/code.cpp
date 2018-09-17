    //cout << s << endl;
    Fireball *f = dynamic_cast<Fireball *>(spell);
    Frostbite *fb = dynamic_cast<Frostbite *>(spell);
    Waterbolt *w = dynamic_cast<Waterbolt *>(spell);
    Thunderstorm *t = dynamic_cast<Thunderstorm *>(spell);

    if(f != NULL) {
        f->revealFirepower();
    }
    else if(fb != NULL) {
        fb->revealFrostpower();
    }
    else if(w != NULL) {
        w->revealWaterpower();
    }
    else if(t != NULL) {
        t->revealThunderpower();
    } 
    else {
        string spell_name = spell->revealScrollName();
        string journal_spell = SpellJournal::journal;
        int m = spell_name.size();
        int n = journal_spell.size();
        int L[m+1][n+1];
        
        for (int i = 0; i < m+1; i++) {
            for (int j = 0; j < n+1; j++) {
                if (i == 0 || j == 0) {
                    L[i][j] = 0;
                } else if (spell_name[i-1] == journal_spell[j-1]) {
                    L[i][j] = L[i-1][j-1] + 1;
                    //cout << spell_name[i-1] << ":" << journal_spell[j-1] << " ";
                } else {
                    L[i][j] = max(L[i-1][j], L[i][j-1]);
                }
            }
        }
        cout << L[m][n] << endl;
    }
