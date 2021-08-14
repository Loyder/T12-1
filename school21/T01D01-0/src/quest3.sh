chmod u+x ai_*.sh
mv -f door_managment_fi door_managment_files
cd door_managment_files
mkdir door_managment_files/door_configuration
mv *.conf door_configuration/
mkdir door_map
mv door_map_1.1 door_map/
mkdir door_logs
mv *.log door_logs/
sh ai_door_managment_module.sh
