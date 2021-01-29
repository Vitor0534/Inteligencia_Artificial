%rede neural para classificação de vinho

%% carrega o dataset
[x,t] = wine_dataset;
size(x)


%cria rede
hiddenLayer1Size = 4;
hiddenLayer2Size = 4;
%%net = fitnet([hiddenLayer1Size hiddenLayer2Size]);
net = patternnet( [hiddenLayer1Size hiddenLayer2Size] );

view(net)


%% net = patternnet(10);


%% treinamento
[net,tr] = train(net,x,t);
nntraintool

%%grafico de desempenho
plotperform(tr)

%%teste da rede
testX = x(:,tr.testInd);
testT = t(:,tr.testInd);

testY = net(testX);
testIndices = vec2ind(testY)

%%matriz de confusão
plotconfusion(testT,testY)

[c,cm] = confusion(testT,testY)

fprintf('Percentage Correct Classification   : %f%%\n', 100*(1-c));

fprintf('Percentage Incorrect Classification : %f%%\n', 100*c);

%%grafico ROC
plotroc(testT,testY)