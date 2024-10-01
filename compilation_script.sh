# Activate the environments
source ~/miniconda3/etc/profile.d/conda.sh

conda activate presto
export PRESTO="/home/panchal/Repositories/presto"
export TEMPO="/home/panchal/Repositories/tempo"

# clean build
cd $PRESTO/src
make cleaner
cd ..

# meson setup step
meson setup build --wipe --prefix=$CONDA_PREFIX

# fixing libraries for check_meson_build.py
export LIBRARY_PATH=/home/panchal/miniconda3/envs/presto/lib/x86_64-linux-gnu:$LIBRARY_PATH

export LD_LIBRARY_PATH=/home/panchal/miniconda3/envs/presto/lib/x86_64-linux-gnu:$LD_LIBRARY_PATH


# check meson build
python check_meson_build.py

# compile
meson compile -C build
meson install -C build

# check prepfold 
prepfold

# installing python codes
cd $PRESTO/python
pip install .



