Compile FeynHiggs
--> path for FeynHiggs in my computer is:
    /usr/local/Caskroom/mambaforge/base/envs/CmHEP-env/
=> compile with:
    g++ fh_higgs_width.cc -I/usr/local/Caskroom/mambaforge/base/envs/CmHEP-env/include -L/usr/local/Caskroom/mambaforge/base/envs/CmHEP-env/lib -lFH -lstdc++ -Wl,-z,noexecstack -o fh_higgs_width.exe
    