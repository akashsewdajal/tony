server {
    listen 80;
    server_name toonparket.nl;

   location / {
        root /var/www/toonparket;
        index index.html index.htm;
    }

    error_page 404 /404.html;
    location = /404.html {
        root /var/www/example.com;
    }

    error_page 500 502 503 504 /50x.html;
    location = /50x.html {
        root /var/www/example.com;
   }
}