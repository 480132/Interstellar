FROM node:iron-bookworm-slim
ENV NODE_ENV=production

WORKDIR /app

COPY ["package.json", "./"]

RUN npm install 

RUN npm run start

COPY . .

CMD [ "node", "index.js" ]
