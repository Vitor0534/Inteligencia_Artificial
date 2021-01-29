% Carrega a rede pré-treinada
alex = alexnet;
layers = alex.Layers;

% Modifica a rede para usar cinco categorias
layers(23) = fullyConnectedLayer(2);
layers(25) = classificationLayer;

% Configurando os dados de treino
imagens = imageDatastore('D:\8º Periodo\IA N2\Redes Neurais\AlexNet\Vitor\Treino', 'IncludeSubfolders', true, 'LabelSource', 'foldernames');
[imagens_treino, imagens_teste] = splitEachLabel(imagens, 0.8, 'randomize');

% Retreinando a redes
opts = trainingOptions('sgdm', 'InitialLearnRate', 0.001, 'MaxEpochs', 20, 'MiniBatchSize', 64);
minhaRede = trainNetwork(imagens_treino, layers, opts);

% Desempenho da rede
predictedLabels = classify(minhaRede, imagens_teste);
acuracia = mean(predictedLabels == imagens_teste.Labels)

plotconfusion (predictedLabels, imagens_teste.Labels)


figure();
img = imread('D:\8º Periodo\IA N2\Redes Neurais\AlexNet\Vitor\Teste\1.png');
label = classify(minhaRede, img );
% Classify the picture
image(img); % Show the picture
title(char(label)); % Show the label

figure();
img = imread('D:\8º Periodo\IA N2\Redes Neurais\AlexNet\Vitor\Teste\2.png');
label = classify(minhaRede, img );



% Classify the picture
image(img); % Show the picture
title(char(label)); % Show the label

figure();
img = imread('D:\8º Periodo\IA N2\Redes Neurais\AlexNet\Vitor\Teste\3.png');
label = classify(minhaRede, img );
% Classify the picture
image(img); % Show the picture
title(char(label)); % Show the label

figure();
img = imread('D:\8º Periodo\IA N2\Redes Neurais\AlexNet\Vitor\Teste\4.png');
label = classify(minhaRede, img );
% Classify the picture
image(img); % Show the picture
title(char(label)); % Show the label

figure();
img = imread('D:\8º Periodo\IA N2\Redes Neurais\AlexNet\Vitor\Teste\6.png');
label = classify(minhaRede, img );
% Classify the picture
image(img); % Show the picture
title(char(label)); % Show the label

figure();
img = imread('D:\8º Periodo\IA N2\Redes Neurais\AlexNet\Vitor\Teste\5.png');
label = classify(minhaRede, img );
% Classify the picture
image(img); % Show the picture
title(char(label)); % Show the label

figure();
img = imread('D:\8º Periodo\IA N2\Redes Neurais\AlexNet\Vitor\Teste\7.png');
label = classify(minhaRede, img );
% Classify the picture
image(img); % Show the picture
title(char(label)); % Show the label