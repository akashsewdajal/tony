
MAKEN
show databases;




INFO

select user(), current_user();

selecteer gebruiker en laat zien:
SELECT User, Host FROM mysql.user;


SHOW GRANTS FOR 'WpUserAdmin'@'localhost';




is een binary file
/usr/sbin/php-fpm 

Solution: voor datbase error: 

	how to solve message: SELinux is preventing /usr/sbin/php-fpm from connectto access on the unix_stream_socket /var/lib/mysql/mysql.sock.#012#012*****  Plugin catchall (100. confidence) suggests   **************************#012#012If you believe that php-fpm should be allowed connectto access on the mysql.sock unix_stream_socket by default.#012Then you should report this as a bug.#012You can generate a local policy module to allow this access.#012Do#012allow this access for now by executing:#012# ausearch -c 'php-fpm' --raw | audit2allow -M my-phpfpm#012# semodule -X 300 -i my-phpfpm.pp#012



	Copilot
	Sent by Copilot:
	It looks like SELinux is blocking php-fpm from connecting to the MySQL socket. You can resolve this by creating a local policy module to allow this access. Here are the steps you can follow:
	Generate a policy module:
	ausearch -c 'php-fpm' --raw | audit2allow -M my-phpfpm

	Install the policy module:
	semodule -X 300 -i my-phpfpm.pp

	This will create and install a policy module that allows php-fpm to connect to the MySQL socket.
	Alternatively, you can set SELinux booleans to allow php-fpm to connect to the network and database:
	Allow network connections:
	setsebool -P httpd_can_network_connect 1

	Allow database connections:
	setsebool -P httpd_can_network_connect_db 1





