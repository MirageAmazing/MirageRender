echo "************************************"
echo MirageRender build begin on Linux
echo "************************************"

str="ME_Render_Build_Linux"

cd ../

if [ ! -e $str ]
then
mkdir $str
fi
cd $str

cmake ../MirageRender

echo "************************************"
echo MirageRender build end on Linux
echo "************************************"
exit 0