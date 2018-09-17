		/* Enter your code here. */
        Server S;
        try {
            cout << S.compute(A,B);
        } catch(bad_alloc &ex) {
            cout << "Not enough memory";
        } catch(exception &ex) {
            cout << "Exception: " << ex.what();
        } catch(...) {
            cout << "Other Exception";
        }
        cout << endl;
