echo "************************************"
echo MERender build begin on Linux
echo "************************************"

str="MERender_Build_Linux"

cd ../

if [ ! -e $str ]
then
mkdir $str
fi
cd $str

cmake ../MirageRender

echo "************************************"
echo MERender build end on Linux
echo "************************************"
exit 0