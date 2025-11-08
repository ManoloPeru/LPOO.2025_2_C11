CREATE TABLE Machine (
MachineId INT PRIMARY KEY,
Name VARCHAR(100),
Type VARCHAR(50),
State VARCHAR(50),
Location VARCHAR(100)
);
-- Insertar máquinas de ejemplo
INSERT INTO Machine VALUES (1, 'Brazo Robótico 1', 'Robótico', 'Operativa', 'Zona A-1');
INSERT INTO Machine VALUES (2, 'Sensor de Visión A2', 'Sensorial', 'En Mantenimiento', 'Zona B-
3');
INSERT INTO Machine VALUES (3, 'Actuador Hidráulico X', 'Actuador', 'Operativa', 'Zona C-2');

CREATE TABLE Maintenance (
    MaintenanceId INT IDENTITY(1,1) PRIMARY KEY,
    MachineId INT,
    Type VARCHAR(20),
    Date VARCHAR(10),
    State VARCHAR(10),
    Description VARCHAR(200),
    Cost  DECIMAL(10,2) NULL
);
